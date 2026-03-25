close all; clear;

% Input signal: 5 cycles
n = 0:99;
x = cos(0.1*pi*n);

% Long impulse response
k = 0:100;
h = 0.99.^k;

% Convolution
y = conv(x, h);
ny = 0:length(y)-1;

% Plot input and output
figure;
plot(n, x, 'b', 'LineWidth', 1.5); hold on;
plot(ny, y, 'r', 'LineWidth', 1.5);
grid on;
xlabel('n');
ylabel('Amplitude');
title('Q3(d): Input and Output Signals');
legend('x[n]', 'y[n]');

% Theoretical frequency response
omega = 0.1*pi;
H = sum((0.99.^k).*exp(-1j*omega*k));

gain = abs(H)
phase = angle(H)