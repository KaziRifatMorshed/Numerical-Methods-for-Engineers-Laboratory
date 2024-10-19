x = [1; 2; 3; 4; 5];
y = [.5; 2; 4.5; 8; 12.5];
% n = size(x)
n = numel(x);

ln_x = log(x);
sum_ln_x = sum(ln_x);
ln_y = log(y);
sum_ln_y = sum(ln_y);

ln_x_sq = ln_x .^ 2;
sum_ln_x_sq = sum(ln_x_sq);
ln_x_ln_y = ln_x .* ln_y;
sum_ln_x_ln_y = sum(ln_x_ln_y);

b = (n * sum_ln_x_ln_y - sum_ln_x * sum_ln_y) / (n * sum_ln_x_sq - (sum_ln_x) ^ 2);
a = exp((1 / n) * (sum_ln_y - b * sum_ln_x));

printf("y = %0.2f x ^ %0.2f", a, b);
% done
