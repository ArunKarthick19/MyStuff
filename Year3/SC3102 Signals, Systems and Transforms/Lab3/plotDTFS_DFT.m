function  plotDTFS_DFT(xn, opStr)
% This function plots the DTFS and DFT of input xn
N = length(xn);
X_DFT = fft(xn);
figure  % this plots the DFT representation of xn for k=0..(N-1)
k=0:length(X_DFT)-1;
subplot(2,1,1); stem(k,abs(X_DFT))
titleStr = sprintf('DFT magnitude/phase spectrum : %s',opStr);
title(titleStr)
xlabel('k'); ylabel('mag')
subplot(2,1,2); stem(k,angle(X_DFT).*(abs(X_DFT)>1e-5))
% comment: we need .*(abs(X_DFT)>0.01)
% to remove phase of very small magnitude
xlabel('k'); ylabel('phase')


X_DTFS = (1/N)*X_DFT;
figure  % this plots the DTFS representation of xn for k=0..(N-1)
k=0:length(X_DTFS)-1;
subplot(2,1,1); stem(k,abs(X_DTFS))
titleStr = sprintf('DTFS (c_k) magnitude/phase spectrum : %s',opStr);
title(titleStr)
xlabel('k of c_k'); ylabel('mag')
subplot(2,1,2); stem(k,angle(X_DTFS).*(abs(X_DTFS)>1e-5))
% comment: we need .*(abs(X_DFT)>0.01)
% to remove phase of very small magnitude
xlabel('k of c_k'); ylabel('phase');

figure;
k_shifted = k-floor(N/2);
subplot(2,1,1); stem(k_shifted, fftshift(abs(X_DTFS)))
titleStr = sprintf('DTFS (c_k) magnitude/phase spectrum : %s',opStr);
title(titleStr)
xlabel('-k..k of c_k'); ylabel('mag')
subplot(2,1,2); stem(k_shifted, fftshift(angle(X_DTFS).*(abs(X_DTFS)>1e-5)))
% comment: we need .*(abs(X_DFT)>0.01)
% to remove phase of very small magnitude
xlabel('-k..k of c_k'); ylabel('phase')


figure;  % plot of DTFT in dirac functions
k_shifted = ((k-floor(N/2))/N)*2*pi/pi;
subplot(2,1,1); stem(k_shifted, fftshift(abs(X_DTFS)),'-^')
titleStr = sprintf('DTFT X(\\Omega) magnitude/phase spectrum  : %s',opStr);
title(titleStr)
xlabel('-\pi to \pi '); ylabel('mag')
subplot(2,1,2); stem(k_shifted, fftshift(angle(X_DTFS).*(abs(X_DTFS)>1e-5)),'-^')
% comment: we need .*(abs(X_DFT)>0.01)
% to remove phase of very small magnitude
xlabel('-\pi .. \pi of X(\Omega)'); ylabel('phase')

end