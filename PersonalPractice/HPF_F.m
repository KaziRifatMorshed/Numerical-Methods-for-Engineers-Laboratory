% Constants
R_F = 15915; % R1  = R_F = 15.915 kΩ
R_1 = 15915; % R1  = R_F = 15.915 kΩ
f = [0:10:100000];
order = [1:1:5];
f_c = 10000; % cut off frequency
A_F = 1 + (R_F / R_1);
colors = ['r', 'g', 'b', 'm', 'k'];

hold on;
grid on;

% High Pass Filter
xlabel('f (Hz)')
ylabel('20 log(V_o/V_in)')
title('Frequency Response of HPF of Order 1 to 5');

for i = 1:5
    V_out_by_V_in_HPF = A_F ./ sqrt(1 + ((f_c / f) .^ (2 * i)));
    y_axis_HPF = 20 * log10(V_out_by_V_in_HPF);
    loglog(f, y_axis_HPF, colors(i));
end

legend('Order 1', 'Order 2', 'Order 3', 'Order 4', 'Order 5');
hold off;
