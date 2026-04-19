clc; clear; close all;

% One period parameters
N = 8;
n = 0:N-1;
k = 0:N-1;

% Signal
x = 2 + 3*cos((pi/4)*n + pi/6) + 2*sin((pi/2)*n - pi/4);

% DTFS coefficients
ck = zeros(1,N);
for kk = 0:N-1
    ck(kk+1) = (1/N) * sum(x .* exp(-1j*2*pi*kk*n/N));
end

% Clean tiny numerical errors
tol = 1e-10;
ck(abs(ck) < tol) = 0;

% Magnitude and phase
mag_ck = abs(ck);
phase_ck = angle(ck);

% Optional: set phase to 0 where magnitude is 0
phase_ck(mag_ck < tol) = 0;

% Plot both like your screenshot
figure;
subplot(2,1,1);
stem(k, mag_ck, 'o', 'LineWidth', 1.5);
grid on;
xlabel('k of c_k');
ylabel('mag');
title('DTFS (c_k) magnitude/phase spectrum');

subplot(2,1,2);
stem(k, phase_ck, 'o', 'LineWidth', 1.5);
grid on;
xlabel('k of c_k');
ylabel('phase');