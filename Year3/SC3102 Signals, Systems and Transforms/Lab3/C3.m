close all; clear;

% Input signal: 5 cycles
n = 0:99;
x = cos(0.1*pi*n);

% Impulse response
h = [0.2 0.3 -0.5];

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
title('Q3(c): Input and Output Signals');
legend('x[n]', 'y[n]');

% Theoretical frequency response at omega = 0.1*pi
omega = 0.1*pi;
H = 0.2 + 0.3*exp(-1j*omega) - 0.5*exp(-1j*2*omega);

gain = abs(H)
phase = angle(H)