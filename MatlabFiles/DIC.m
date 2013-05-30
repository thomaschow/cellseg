function [DICmask] = DIC(OrigImage)
%%%convert rgb to grayscale.%%%
origImage = imread(OrigImage);
x = size(size(origImage));
grayscale = origImage;
if x(2) == 3
    grayscale = rgb2gray(origImage);
end
% grayscale = normalize(grayscale, 0, 255);

smoothFilter = fspecial('gaussian', [25 25], .5);
smoothed = medfilt2(grayscale);
%%% apply preliminary processing. Sobel edge detection to find edges of cells, apply dilation and filling to acquire whole cell. %%%
seD = strel('disk',2,8);
adjusted = imadjust(grayscale);
hy = fspecial('sobel');
hx = hy';
Iy = imfilter(double(smoothed), hy, 'replicate');
Ix = imfilter(double(smoothed), hx, 'replicate');
% gradmag = sqrt(Ix.^2 + Iy.^2);
[gradmag graddir] = imgradient(smoothed, 'sobel');
max(gradmag(:))
figure, imshow(gradmag, []);
% gradmag = imadjust(gradmag, [min(gradmag(:)), max(gradmag(:))] , [0, 1]);
imwrite(gradmag, 'Gradient', 'png');
edgePenal = 1 ./ (1 + gradmag);

regionalMax = imregionalmax(gradmag);
[edges thresh] = edge(adjusted,'sobel');
seC = strel('disk',3,4);

% gradmag2 = gradmag,[];
BWc = imclose(edges, seC);
BWf = imfill(BWc,'holes');
seD = strel('disk',3,4);
BWe = imerode(BWf,seD);

objectList = bwlabel(BWe);

%%% Apply area filtering to eliminate small islands. %%%
stats = regionprops(BWe, 'Perimeter','Area');
index = find([stats.Area] > 500);
BWe = ismember(objectList, index);

%%% Watershed technique to distinguish clumped cells. %%%
% distanceTrans = -bwdist(~BWe,'euclidean');
% distanceTrans(~BWe) = -Inf;
% wshed = watershed(distanceTrans);
% BWe(wshed == 0) = 0;


%%% Apply binary mask to original image. Label connected components.%%%
BWfinal = cast(BWe, class(grayscale));
maskedImage = (grayscale).*(BWfinal);
maskedImage = imclose(maskedImage, strel('disk',3,4));
L = bwlabel(maskedImage,4);
colorObjects = label2rgb(L);



%%% Show images of processing stages. %%%
subplot (3,3,1), imshow(grayscale);
title('Grayscale image')
subplot (3,3,2), imshow(smoothed);
title('Smoothed image')
subplot (3,3,3), imshow(adjusted);
title('Smoothed image')
subplot (3,3,4), imshow(-edgePenal);
title('Edge Penalization image')
subplot (3,3,5), imshow(edges);
title('Edged image')
subplot (3,3,6), imshow(BWc);
title('Closed image')
subplot (3,3,7), imshow(BWf);
title('Eroded image')
subplot (3,3,8), imshow(gradmag, [0 255]);
title('Gradient')
subplot (3,3,9), imshow(maskedImage), hold on
himage = imshow(colorObjects);
set(himage,'AlphaData',.5);
title('Masked image')

DICmask = maskedImage;

%     segmentedCells = cell(1, cc.NumObjects);
%     cc.NumObjects
%     for i = 1: cc.NumObjects
%         subplot (ceil(cc.NumObjects / 10), 10 ,i) , imshow(L == i)
%         segmentedCells{i} = (L==i);
%     end
%


%%% Hough transform to detect circles.%%%
[circen, cirrad, metric]= imfindcircles(origImage, [15 40],'Sensitivity', .9, 'ObjectPolarity', 'bright');
[circen1, cirrad1, metric1]= imfindcircles(origImage, [15 40],'Sensitivity', .9, 'ObjectPolarity', 'dark');




%%% use circle centers as seeds to propagate cell detection.%%%

% dImage = dilation(origImage, adjusted, round(circen), gradmag, thresh);
% figure, imshow(dImage);



% plot(circen(:,1), circen(:,2), 'b+');
% for ii = 1 : size(circen, 1)
%     rectangle('Position',[circen(ii,1) - cirrad(ii), circen(ii,2) - cirrad(ii), 2*cirrad(ii), 2*cirrad(ii)],...
%         'Curvature', [1,1], 'edgecolor', 'b', 'linewidth', 1.5);
% end
% for ii = 1 : size(circen1, 1)
%     rectangle('Position',[circen1(ii,1) - cirrad1(ii), circen1(ii,2) - cirrad1(ii), 2*cirrad1(ii), 2*cirrad1(ii)],...
%         'Curvature', [1,1], 'edgecolor', 'r', 'linewidth', 1.5);
% end


hold off;


end

function [normalizedIm] = normalize(image, minimum, maximum)
MAX = max(max(image)');
MIN = min(min(image)');
newMAX = max(max(image)');
newMIN = min(min(image)');
normalizedIm = (image - MIN) .*((newMAX - newMIN)/ (MAX-MIN)) +newMIN;

end



function [dilatedImage] = dilation(origImage, grayscale, seeds, gradmag, thresh)
closedPoints = [];

accumFn = @(intensity,accruedPixels) intensity/accruedPixels;

     
for i = 1;
    coloredPixels = 0;
    q = [];
    q(1,1) = seeds(i,1);
    q(1,2) = seeds(i,2);
%     [D, idx] = bwdist(edges);
%     [xNear, yNear] = ind2sub(size(edges), idx);
    while (coloredPixels < 6000);
        currPoint = [q(1,1), q(1,2)];
        q(1,:) = [];
        closedPoints(end+1,:) = currPoint;
        origImage(currPoint(2),currPoint(1),1) = 255;
        origImage(currPoint(2),currPoint(1),2) = 255;
        origImage(currPoint(2),currPoint(1),3) = 255;
        coloredPixels = coloredPixels + 1;
        neighbors = getNeighbors(currPoint,closedPoints, 1);
        for i = 1: length(neighbors(:,1));
            if (~ismember(neighbors(i,:), q, 'rows') && gradmag(neighbors(i,2), neighbors(i,1)) < max(max(gradmag))/6)
                q(end+1,:) = neighbors(i,:);
            end
        end
    end
end
dilatedImage = origImage;
end


function [closedCurve] = curveFit(origImage, grayscale, seeds, gradmag, thresh)

for i = 1;
    start = [seeds(i,1), seeds(i,2)];
    circleFn = @(xp,yp, xc, yc,r) sqrt((xp-xc)^2 + (yp-yc)^2) - r;
    iterations = 0;
    while( iterations < 300)
        
    
end

end
end

function [neighbors] = getNeighbors(point, closedPoints, connectivity)
neighbors = [];
count = 1;
for i = -connectivity:connectivity
    for j = -connectivity:connectivity
        if (~(i ==0 && j==0) && ~ismember([point(1) + i, point(2) + j], closedPoints,'rows'))
            neighbors(count,1) = point(1) + i;
            neighbors(count,2) = point(2) + j;
            count = count + 1;
        end
    end
end
end

function [foci] = convertToEllipse(circen, cirrad)

for i = 1: size(circen,1)
    [x, y] = circen(i,1), circen(i,2);
    for j = 1: size(circen,1)
        if j ~= i
            [xcomp, ycomp] = circen(j,1), circen(j,2);
            if cirrad(i)+cirrad(j) > sqrt(square(xcomp -x) + square(ycomp - y))
                calculateEllipse([x,y], [xcomp,ycomp], cirrad(i), cirrad(j));
            end
        end
    end
end

end

function [ellipse] = calculateEllipse(center1, center2, rad1, rad2)
majorAxis = sqrt(square(xcomp -x) + square(ycomp - y)) + rad1 + rad2;
minorAxis = max(rad1,rad2);
centerx = sqrt(square(xcomp -x) + square(ycomp - y))
end
