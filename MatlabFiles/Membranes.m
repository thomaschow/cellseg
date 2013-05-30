function [Membranes] = Membranes(OrigImage, DICImage)


functionResult.outputImage = cell(0);
functionResult.imageTitle = cell(0);
cellRad = [15 40];
DICmask = DIC(DICImage);
functionResult = store(functionResult, DICmask, ['DIC mask']);
I = imread(OrigImage);
functionResult = store(functionResult, I, 'Original Image');

channels = cell(0)

for i = 1:3
    channels{i} = normalize(I(:,:,i), 0, 255);
    functionResult = store(functionResult, channels{i}, ['Channel ', num2str(i)]);
    
end


seOpen = strel('disk', 15);
for i = 1:3
    channels{i} = imtophat(channels{i}, seOpen);
    channels{i}(~DICmask) = 0;
    channels{i} = imadjust(channels{i});
    functionResult = store(functionResult, channels{i}, ['Channel ', num2str(i), ' tophat + DICmask + adjusted']);
end



% figure, surf(double(channels{1}(1:8:end,1:8:end))),zlim([0 255]);

print(functionResult);
end

function [normalizedIm] = normalize(image, minimum, maximum)
    MAX = max(max(image)');
    MIN = min(min(image)'); 
    newMAX = max(max(image)');
    newMIN = min(min(image)');
    normalizedIm = (image - MIN) .*((newMAX - newMIN)/ (MAX-MIN)) +newMIN;
   
end

function [] = print(printStruct)
numProcesses = length(printStruct.outputImage);
cols = 4;
rows = ceil(numProcesses / cols);
for i = 1:numProcesses
    subplot (rows,cols,i), imshow(printStruct.outputImage{i})
    title(printStruct.imageTitle{i})
    
end
end

function [structArray] = store(inStruct, image, title)
inStruct.outputImage{end+1} = image;
inStruct.imageTitle{end+1} = title;
structArray = inStruct;
end