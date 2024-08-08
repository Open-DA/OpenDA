% 定义函数句柄
func = @(t,y) [
    (Cp+Cx)*(Vc./R2(t)) ./ alpha - ((R2(t)+R4(t))*(Cp+Cx).*y(1))./(R2(t)*R4(t)*alpha) - ((R1(t)+R3(t))*Cx.*y(2))./(R1(t)*R3(t)*alpha);
    (Cx*Vc./R2(t)) ./ alpha - ((R2(t)+R4(t))*Cx.*y(1))./(R2(t)*R4(t)*alpha) - ((R1(t)+R3(t))*(Cp+Cx).*y(2))./(R1(t)*R3(t)*alpha);
    -(1/(Rf*Cf))*y(3) - (1/(R4(t)*Cf))*y(2) 
];

% 初始值
y0 = [0;0;0];

% 参数
alpha = 0.995;
Vc = 12;
Cp = 8e-6;
R1 = @(t) 200 + 200*sin(pi*t/12); % 可以设置为任意函数
R2 = @(t) 10 + 10*sin(pi*t/12);
R3 = @(t) 400 + 400*sin(pi*t/12);
R4 = @(t) 20 + 20*sin(pi*t/12);
Cf = 10e-6;
Cx = 2e-12;
Rf = 200e3;

% 求解微分方程
tspan = [0 60]; % 求解时间区间
options = odeset('RelTol',1e-6,'AbsTol',1e-10); % 指定求解精度
[t,y] = ode45(func,tspan,y0,options);

% 画图
figure
plot(t,y(:,3))
xlabel('时间（s）')
ylabel('Vo（V）')