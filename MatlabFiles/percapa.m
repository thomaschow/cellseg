function [perreg, rfpfilbw, gfpfilbw, perc, cellc, n, nc, xout] = percapa(rfp, gfp)

rfp=uint16(rfp); %convert rfp image from uint8 to uint16 (HSR)
gfp=uint16(gfp); %convert gfp image from uint8 to uint16 (HSR)

lnoise=1;
lobject=12;

rfpfil = bpass(double(rfp), lnoise ,lobject);  % spatial band pass filtering the RFP image %pretty arbitrary but should check actual pic

rfpthresh=20;

rfpfilbw = rfpfil > rfpthresh; % thresholding the filtered image 
% gives everything >25 value of 1, rest 0
% this above step can be adjusted to give threshold value that may more
% accurately depict RFP channel of specific image 
% check that this looks right by eye by comparing with other image 
rfpfilbwlabel = bwlabel(rfpfilbw); % segmentation %%helps identify an object from background 0's->bckgrnd, 1's->obj1, 2's->obj2

figure;imagesc(rfp + uint16(bwperim(rfpfilbw)) * 4096);  % draw boundaries around each RFP punctate
%BW2 = BWPERIM(BW1) returns a binary image containing only the perimeter pixels of objects in the input image BW1. A pixel is part of the perimeter if it nonzero and it is connected to at least one zero-valued pixel.



gfpfil = imfilter(gfp, fspecial('gaussian', 5,5));  % gaussian filtering the Venus image

gfpthresh=150;

gfpfilbw = gfpfil > gfpthresh;  % thresholding the filtered image
%this threshold should ideally be the same for each construct since all
%cytosolic GFP driven by RPL18B, but based on exposure it can vary. Check.
%value is pretty arbitrary, just pick a spot in pic that u think is lowest
%GFP level in cytosol
figure;imagesc(gfp + uint16(bwperim(gfpfilbw)) * 4096); % draw boundaries around each cell
gfpfilfig=gfp + uint16(bwperim(gfpfilbw)) * 4096; %renaming fig to be able to put it into subplot later

gfpfilbw = gfpfilbw & ~rfpfilbw;   % substract out the rfp image from the venus image (i.e. cells)

perreg=zeros(max(max(rfpfilbwlabel)),3); %initialize instead using zeros. Added by Harneet b/c error saying "perreg" not defined

for i = 1:max(max(rfpfilbwlabel))                 
    perreg(i,1) = sum(rfp(rfpfilbwlabel == i));   % calculate total intensity of a rfp punctum
    perreg(i,2) = sum(sum(rfpfilbwlabel == i));   % calculate the total area of a rfp punctum
    perreg(i,3) = perreg(i,1) / perreg(i,2);      % calculate the "rfp concentration (intensity/px)" of a rfp punctum
end

%figure;hist(perreg(:,2),50);                       % plot histograms
%figure;hist(perreg(:,3),50);
%figure;scatter(perreg(:,2), perreg(:,3));


perc = sum(rfp(rfpfilbw))/sum(sum(rfpfilbw));        % calculate the average concentration of all punctates of rfp

cellc = sum(rfp(gfpfilbw))/sum(sum(gfpfilbw));       % calculate the average concentration of cells of rfp

cellint = rfp .* uint16(gfpfilbw);                % draw the intensity distribution

perint = rfp .* uint16(rfpfilbw);

[n, xout] = hist(makeflat(double(perint))', 50);
nc = hist(makeflat(double(cellint))', xout);

nc1 = nc / max(nc(2:length(nc)));
n1 = n / max(n(2:length(n)));

figure;plot(xout, nc1);hold on;plot(xout, n1,'red');ylim([0,1]);

%subplot(2,2,1)
%imagesc(rfp)
%title('RFP channel unfiltered')
%subplot(2,2,2)
%imagesc(gfp)
%title('GFP channel unfiltered')
%subplot(2,2,3)
%imagesc(rfp + uint16(bwperim(rfpfilbw)) * 4096)
%title('filtered RFP channel with circled peroxisomes')
%subplot(2,2,4)
%imagesc(gfpfilfig)
%title('filtered GFP channel')

end %function percapa
