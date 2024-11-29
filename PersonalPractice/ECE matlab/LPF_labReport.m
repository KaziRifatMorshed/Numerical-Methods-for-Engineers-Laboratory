% Constants
R_F = 2200; % R1  = R_F = 2.2 kΩ
R_1 = 2200; % R1  = R_F = 2.2 kΩ
f = [0:10:100000];
f_c = 1000; % cut off frequency
A_F = 1 + (R_F / R_1);

hold on;
grid on;

% Low Pass Filter
xlabel('f (Hz) (Logarithmic Scale)')
ylabel('20 log(V_o/V_in) (Logarithmic Scale)')
title('Frequency Response of a LPF of 1st order');

V_out_by_V_in_LPF = A_F ./ sqrt(1 + ((f ./ f_c) .^ (2)));
y_axis_LPF = 20 * log10(V_out_by_V_in_LPF);
loglog(f, y_axis_LPF, 'r');

legend('Order 1');
hold off;
