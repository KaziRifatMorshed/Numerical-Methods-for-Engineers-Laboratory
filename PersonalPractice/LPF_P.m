% Constants
f = [0:10:100000];
f_c = 1000; % cut off frequency
grid on;
hold on;
% Low Pass Filter
xlabel('f (Hz)');
ylabel('Magnitude(in Degree)');
title('Phase Response of LPF');

y_axis_LPF = -atand(f / f_c);
plot(log10(f), y_axis_LPF);

hold off;
