a = 1;
b = 9;

alpha_a = 0.968;
beta_a = 0.02;
alpha_b = 0.04;
beta_b = 0.99;

num_steps = 20;
time = 1:num_steps;

a_values = zeros(1, num_steps);
b_values = zeros(1, num_steps);
c_values = zeros(1, num_steps);

for t = 1:num_steps
    a_values(t) = a;
    b_values(t) = b;
    c_values(t) = a+b;

    a_next = alpha_a * a + beta_a * b;
    b_next = alpha_b * a + beta_b * b;
    
    a = a_next;
    b = b_next;
end

fid = fopen('data.txt', 'w');
fprintf(fid, 'Time\t 城市\t 农村\t 总人口\n');
fprintf(fid, '%d\t %f\t %f\t %f\n', [time; a_values; b_values; c_values]);
fclose(fid);

figure;
plot(time, a_values, 'r', 'LineWidth', 1, 'DisplayName', '城市人口');
hold on;
plot(time, b_values, 'b', 'LineWidth', 1, 'DisplayName', '乡村人口');
hold on;
plot(time, c_values, 'g', 'LineWidth', 1, 'DisplayName', '总人口');

scatter(time, a_values, 'ro');
scatter(time, b_values, 'bo');
scatter(time, c_values, 'go');

xlabel('时间步');
ylabel('变量值');
title('城乡人口演变');
legend('Location', 'Best');
grid on;
hold off;
