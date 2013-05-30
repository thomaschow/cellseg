function [perreg, rfpfilbw, gfpfilbw, perc, cellc, n, nc, xout, per_tot, cyt_tot, area_avg, num_perox] = DIMpro(rfp, gfp)
 
%rfp=uint16(rfp); %convert rfp image from uint8 or other format to uint16 (HSR)
%gfp=uint16(gfp); %convert gfp image from uint8 or other format to uint16 (HSR)
 
lnoise=1;
lobject=25;
 
rfpfil = bpass(double(rfp), lnoise ,lobject);  % spatial band pass filtering the RFP image %pretty arbitrary but should check actual pic
 
rfpthresh=750;

rfpfilbw = rfpfil > rfpthresh; % thresholding the filtered image (if greater then assign 1, other 0)

rfpfilbwlabel = bwlabel(rfpfilbw); % segmentation (helps identify an object from background 0's->bckgrnd, 1's->obj1, 2's->obj2)

figure; imagesc(rfpfil);
figure;imagesc(uint16(rfpfil) + uint16(bwperim(rfpfilbw)) * 7e4);  % draw boundaries around each RFP punctate
 %can change 7e4 to less or higher to make outlining of peroxisomes clearer
 
gfpfil = imfilter(gfp, fspecial('gaussian', 5,5));  % gaussian filtering the Venus image

gfpthresh=2400; 

gfpfilbw = gfpfil > gfpthresh;  %thresholding the filtered image

%figure;imagesc(double(gfp) + double(bwperim(gfpfilbw)) * 4096); % draw boundaries around each cell
gfpfilfig= double(gfp) + double(bwperim(gfpfilbw)) * 4096; %renaming fig to be able to put it into subplot later

gfpfilbw = gfpfilbw & ~rfpfilbw;   % substract out the rfp image from the venus image (i.e. cells)

figure; image (gfpfilbw);
perreg=zeros(max(max(rfpfilbwlabel)),3); %initialize instead using zeros. 
 
for i = 1:max(max(rfpfilbwlabel))                 
    perreg(i,1) = sum(rfp(rfpfilbwlabel == i));   % calculate total intensity of a rfp punctum
    perreg(i,2) = sum(sum(rfpfilbwlabel == i));   % calculate the total area of a rfp punctum
    perreg(i,3) = perreg(i,1) / perreg(i,2);      % calculate the "rfp concentration (intensity/px)" of a rfp punctum
end
 
%figure;hist(perreg(:,2),50);                       % plot histograms
%figure;hist(perreg(:,3),50);
%figure;scatter(perreg(:,2), perreg(:,3));

per_tot=sum(perreg(:,1)); %calculate total intensity of rfp in perox
cyt_tot=sum(rfp(gfpfilbw)); %calculate total intensity of rfp in cytosol

area_avg=mean(perreg(:,2)); %calculate average peroxisome area in image (note some peroxisome clusters can count as 1 big perox)
num_perox=length(perreg(:,2)); %calculate number of peroxisomes in image (note some images have more cells than others)

perc = sum(rfp(rfpfilbw))/sum(sum(rfpfilbw));        % calculate the average concentration of all punctates of rfp
 
cellc = sum(rfp(gfpfilbw))/sum(sum(gfpfilbw));       % calculate the average concentration of cytosolic rfp (intensity/px)
cellarea=sum(sum(gfpfilbw));    %calculate total area of cytosol (like 2D volume)

cellint = double(rfp) .* double(gfpfilbw);                % draw the intensity distribution
 
perint = double(rfp) .* double(rfpfilbw);
 
[n, xout] = hist(makeflat(double(perint))', 50);
nc = hist(makeflat(double(cellint))', xout);
 
nc1 = nc / max(nc(2:length(nc)));
n1 = n / max(n(2:length(n)));
 
%figure;plot(xout, nc1);hold on;plot(xout, n1,'red');ylim([0,1]);


end %function DIMpro


