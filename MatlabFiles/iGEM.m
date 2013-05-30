function [markedImage, imageArray]  = iGEM(venus)

I = imread(venus);
figure, imshow(I);


drawnow;
caption = sprintf('Original "coins" image showing\n6 nickels (the larger coins) and 4 dimes (the smaller coins).');
title(caption); 
axis square; % Make sure image is not artificially stretched because of screen's aspect ratio.

% Just for fun, let's get its histogram.
[pixelCount grayLevels] = imhist(I);
subplot(3, 3, 2); 
bar(pixelCount); title('Histogram of original image');
xlim([0 grayLevels(end)]);





level = graythresh(I);
% background = imopen(I,strel('disk',5));
% 
% I2 = I - background;
bw = im2bw(I, level);

figure, imshow(bw);
 
BWoutline = bwperim(bw);
Segout = I;
Segout(BWoutline) = 255;
figure, imshow(Segout), title('outlined original image')

% 
% figure, imshow(I)
% 

% figure, imshow(bw)
% bw2 = imfill(bw,'holes');
% bw3 = imopen(bw2, ones(5,5));
% bw4 = bwareaopen(bw3, 40);
% bw4_perim = bwperim(bw4);
% overlay1 = imoverlay(I, bw4_perim, [.3 1 .3]);
% figure, imshow(overlay1)

I2 = I - background;
%figure, imshow(I2)

%bw = im2bw(I2,level);

%figure, imshow (bw)

%cc = bwconncomp(bw,12);
%cc.NumObjects
    
%labeled = labelmatrix(cc);


%BW_label = label2bw(labeled, @spring, 'c', 'shuffle');
%figure, imshow(RGB_label)

%figure, imshow(labeled);
end