% Constants
f = [0:10:100000];
f_c = 1000; % cut off frequency
grid on;
hold on;
% High Pass Filter
xlabel('f (Hz) (Logarithmic Scale)');
ylabel('Magnitude(in Degree)');
title('Phase Response of HPF');

y_axis_LPF = atand(f_c ./ f);
semilogx(f, y_axis_LPF);

hold off;
