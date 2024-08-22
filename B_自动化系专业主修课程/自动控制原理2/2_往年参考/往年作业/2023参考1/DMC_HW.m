clear all;
figure(1);

%% Sampling time
Ts = 0.05;
%% Step-Response Horizon
N = 15;
%% Prediction Horizon
P = 20;
%% Control Horizon
L = 5;

%% Set simulation horizon
T = 3;
M = round(T/Ts);
t = (0:M)'*Ts;

%% 从预测模型获得阶跃响应
sysd0 = ss(tf([1],[1 1.1 0.28],Ts));  % 定义z-传递函数并转换为状态空间模型
y0 = step(sysd0,t);
s = [y0(1:N);y0(N)*ones(P,1)];

%% 从实际模型获得阶跃响应 
sysd = ss(tf([1],[1 1 0.25],Ts)); % 定义z-传递函数并转换为状态空间模型
y = step(sysd,t);

%% 参考轨迹
w = ones(M+P,1);

%% 计算动态矩阵
A = zeros(P,L);
for k = 1:L
    A(k:P,k) = s(1:P-k+1);
end
A0 = zeros(P,N);
for k = 1:P
    A0(k,:) = (s(N+k:-1:1+k)-s(N:-1:1))';
end

%% 权重系数
Q = eye(P);
R = 0.2*eye(L);

%% 反馈增益
d = ([1,zeros(1,L-1)]*inv(A'*Q*A+R)*A'*Q)';

%% Initialization
x = [0;0];
u = 0;
ym = sysd.C*x;
Du = [];  % 控制增量序列 Delta_u(k) 
wP = w(1:P);
Du_Past = zeros(N,1);
yP0 = ym(end)*ones(P,1);

%% 滚动窗口优化
for k = 1:M
    Du = [Du;d'*(wP-yP0)];
    u  = [u; u(end)+Du(end)];
    x  = [x,sysd.A*x(:,end) + sysd.B*u(end)];
    ym = [ym;sysd.C*x(:,end)];
    wP = [wP(2:end);w(k+P)];          % Receding horizon
    Du_Past = [Du_Past(2:N);Du(end)]; % Receding horizon
    yP0 = ym(k)*ones(P,1)+A0*Du_Past;    
end

LW = 1.5;
subplot(3,1,1);
plot(t,y0,'-.',t,y,'r','LineWidth',LW); hold on;
stem(t(1:N),s(1:N),'k');   hold off;
title('Predicted Response')
xlabel('Time (s)');
ylabel('y');
legend('Predicted Response','Real Response');
subplot(3,1,2);
plot(t,w(1:M+1),t,ym,'r','LineWidth',LW);
title('Actual Output')
xlabel('Time (s)');
ylabel('y');
legend('Reference Signal','Real Output');
subplot(3,1,3);
stairs(t(1:end-1),u(2:end),'r','LineWidth',LW);
title('Control Sequence');
xlabel('Time (s)');
ylabel('u');



