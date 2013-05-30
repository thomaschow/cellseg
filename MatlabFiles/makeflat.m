function y = makeflat(x); %2D --> 1D array

for i = 1:size(x,1)
    y((i-1)*size(x,2)+1:i*size(x,2)) = squeeze(x(i,:));
end
    

