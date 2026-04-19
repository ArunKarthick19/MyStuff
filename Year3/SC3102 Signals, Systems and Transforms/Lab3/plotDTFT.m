function  plotDTFT(xn, xn_idx, opStr)
% This function plots the DTFT of a finite sequence of xn
N = length(xn); X_DFT = fft(xn);
% this plots the DFT representation of xn for n given by xn_idx
w = -pi:pi/101:pi; % dividing -pi to pi by 101 points
% X(w) = \sum_{n for x[n]~=0 range} x[n]*exp(-j*\Omega)*n
X_w = zeros(length(w),1);
for k=1:length(w)
 w_val =w(k); tmpSum  = 0;
    for n=1:length(xn)
        tmpSum = tmpSum +  xn(n)*exp(-j*w_val*xn_idx(n));
    end  % of for l
 X_w(k) = tmpSum;
end % of for k

figure; subplot(2,1,1); stem(w,abs(X_w))
titleStr = sprintf('DTFT magnitude/phase spectrum : %s',opStr);
title(titleStr) xlabel('\Omega '); ylabel('mag')
subplot(2,1,2); stem(w,angle(X_w))
xlabel('\Omega'); ylabel('phase')
