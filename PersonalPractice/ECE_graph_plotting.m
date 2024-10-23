% Constants
R_F = 1000;
R_l = 1000;
f = [0:10:100000]; % x-axis
order = [1:1:6];
f_c = 1000; %y_axis_low
A_F = 1 + (R_F / R_l);
colors = ['r', 'g', 'b', 'c', 'm', 'k'];

% Low Pass Filter
% V_out_by_V_in_low = A_F * (1 ./ sqrt(1 + (f / f_c) .^ (2)));
% y_axis_low = 20 * log(V_out_by_V_in_low);

hold on;
grid on

% plot(f, y_axis_low)
% loglog(f, y_axis_low, "r")
xlabel('f (Hz)')
ylabel('20log(V_o/V_in)')
title('Frequency Response of 1th to 6th Order LPF')

for i = 1:6
    V_out_by_V_in_low = A_F * (1 ./ sqrt(1 + (f / f_c) .^ (2 * i)));
    y_axis_low = 20 * log(V_out_by_V_in_low);
    loglog(f, y_axis_low, colors(i));
end

hold off;

% High Pass Filter

% title('Frequency Response of 1th to 6th Order HPF')
% hold on;

% for i = 1:6
%     V_out_by_V_in_high = A_F * (1 ./ sqrt(1 + (f_c / f) .^ (2 * i)));
%     y_axis_low = 20 * log(V_out_by_V_in_high);
%     loglog(f, y_axis_low, colors(i));
% end

% hold off;
