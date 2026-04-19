% Lab solution: FT for discrete time signals
% Author: Chng ENg Siong
% 30 Jan 2025

% Q1, generate DT representation of signals

close all; clear all;

% Given y1(t) = 2cos(2*π*2*t),  y2(t) = 3sin(2* π *10*t-π/3),  and y3(t) = y1(t)+y2(t) sampled at Fs = 100.
Fs = 100; T = 1/Fs;
% y1(nT) = 2cos(2*π*2*n/Fs) ;  N1 = 50 samples == period
% y2(nT) = 3sin(2*π*10*n/Fs -π/3 ) ; N2 == 10 samples == period
% y3(nT) = 2cos(2*π*2*n/Fs) +3sin(2*π*10*n/Fs -π/3 ); 
% y3's period == LCM of N1, N2 == 50


N3 = 50; % the period of N3;
n = 0:(11*N3-1);  % lets generate 10 period of y3(n)

w1 = pi/25; y1 = 2*cos(w1*n);
w2 = pi/5;  y2 = 3*sin(w2*n-pi/3);
y3=y1+y2;
figure(1);
stem(n(1:2*N3),y1(1:2*N3),'g--'); hold on;
stem(n(1:2*N3),y2(1:2*N3),'b--');
plot(n(1:2*N3),y3(1:2*N3),'r-+');
title('DT representation of y3')
legend('y1','y2','y3')

%Q1b(i)
% Q1B) DTFS and DFT of 
opStr = sprintf(' y3  using %d samples',N3);
plotDTFS_DFT(y3(1:N3),opStr); % plot 1 period of DTFS, DFT of y3


%Q1b(iv)
% Lets use 2*N3 samples
opStr = sprintf(' y3  using %d samples',N3*2);
plotDTFS_DFT(y3(1:2*N3),opStr); % plot 2 period of DTFS, DFT of y3

%Q1b(iv)
% Lets use 10*N3 samples
opStr = sprintf(' y3  using %d samples',N3*10);
plotDTFS_DFT(y3(1:10*N3),opStr); % plot 10 period of DTFS, DFT of y3

% What we observe is that there is more samples in the horziontal axis




%Q1b(iii) Spectral leakage, using 2 period+1 samples
% Q1B) DTFS and DFT of 
opStr = sprintf('(spectral leak demo) y3  using %d samples',10*N3+1);
plotDTFS_DFT(y3(1:10*N3+1),opStr); % plot 10 period +1 samples of DTFS, DFT of y3
