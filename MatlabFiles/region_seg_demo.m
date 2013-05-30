% Demo of "Region Based Active Contours"
%
% Example:
% seg_demo
%
% Coded by: Shawn Lankton (www.shawnlankton.com)

I = imread('14pre_DIC.png');  %-- load the image
m = zeros(size(I,1),size(I,2));          %-- create initial mask
m(150:180,180:210) = 1;

I = imresize(I,.5);  %-- make image smaller 
m = imresize(m,.5);  %     for fast computation
Im = I;
Im(:,:,1) = I(:,:,1) + cast(m.*255, class(I));
Im(:,:,2) = I(:,:,2) + cast(m.*255, class(I));
Im(:,:,3) = I(:,:,3) + cast(m.*255, class(I));
subplot(2,2,1); imshow(Im); title('Input Image');
subplot(2,2,2); imshow(m); title('Initialization');
subplot(2,2,3); title('Segmentation');

seg = region_seg(I, m, 500); %-- Run segmentation

subplot(2,2,4); imshow(seg); title('Global Region-Based Segmentation');


