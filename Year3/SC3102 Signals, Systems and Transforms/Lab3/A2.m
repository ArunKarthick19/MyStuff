close all; clear;

N = 50;
n = 0:N-1;
k_list = [0 1 -1 49];

for idx = 1:length(k_list)
    k = k_list(idx);
    Wk = exp(1j*(2*pi/N)*k*n);

    % 2D polar plot
    figure;
    polarplot(angle(Wk), abs(Wk), 'o-');
    title(sprintf('Polar plot of W^{k}, k = %d', k));

    % 3D plot: n vs real vs imag
    figure;
    plot3(n, real(Wk), imag(Wk), 'o-');
    grid on;
    xlabel('n');
    ylabel('Real Part');
    zlabel('Imag Part');
    title(sprintf('3D plot of W^{k}, k = %d', k));
end