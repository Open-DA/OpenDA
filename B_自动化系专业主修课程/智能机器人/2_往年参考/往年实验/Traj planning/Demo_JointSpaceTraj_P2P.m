% 关节空间轨迹规划（P2P-straight line）
clc
clear
close all

% +++++++++++++++++++++++++++++++++++++++++++++++++
% Robot by DH parameters
%           theta d    a    alpha       offset      
L(1) = Link([0    0    0     -pi/2      0]);
L(2) = Link([0    0    1     0          0]);
L(3) = Link([0    0    1     0          0]);
robot = SerialLink(L, 'name', '3-Link Bot');
m = [1,1,1,0,0,0];

% +++++++++++++++++++++++++++++++++++++++++++++++++
% 采样时间为T，采样间隔为0.01s
T = 2;
dT = 0.05;
t = 0: dT: T;  

% 笛卡尔空间中的起点和终点
Ts = transl(1.2, -0.2, -0.5) ;  % 如果有姿态再用上trotex,y,z等函数
Te = transl(-0.8, 0.8,  0.7) ;

% 关节空间的起点和终点
% 可以直接从关节空间中指定，此处为了显示动画的设计更好理解，从笛卡尔空间变换过来
qs0 = [0  0  0]; 
qs = robot.ikine(Ts,'q0', qs0, 'mask', m);

qe0 = [0  0  0]; 
qe = robot.ikine(Te,'q0', qe0, 'mask', m);

% 关节空间轨迹规划
% 默认采用（关节空间）五阶多项式，速度和加速度为零边界条件 
[q, qd, qdd] = jtraj(qs, qe, t); 

% 笛卡尔空间轨迹规划
Nc =  T/dT+1;
Tc = ctraj(Ts, Te, Nc);

% +++++++++++++++++++++++++++++++++++++++++++++++++
% 显示机器人及其末端的轨迹
% 目前的RTB在mlx格式文件中不能显示动画，必须用m文件的方式
figure('position',[100, 250, 800,920])
axis equal;
robot.plot(q,'trail',{'b', 'LineWidth', 2}, 'nowrist', 'notiles');

figure;
plot3(q(:,1), q(:,2), q(:,3),'b', 'LineWidth', 2); hold
plot3(q(1,1), q(1,2), q(1,3),'r*','LineWidth', 2); 
xlabel('Joint1(rad)');  
ylabel('Joint2(rad)'); 
zlabel('Joint3(rad)');
grid
axis equal

% +++++++++++++++++++++++++++++++++++++++++++++++++
% 显示关节N的规划曲线
N = 1;
fname = sprintf('%s%d','Data of Joint-',N);
figure('name',fname);

subplot(3,1,1); 
plot(t,q(:,N),'r','LineWidth', 1.5);
xlabel('time(s)');  ylabel('Joint Angle(rad)');
grid;

subplot(3,1,2);
plot(t,qd(:,N),'g','LineWidth', 1.5);
xlabel('time(s)');  ylabel('Joint Vel(rad/s)');
grid;

subplot(3,1,3);
plot(t,qdd(:,N),'b','LineWidth', 1.5);
xlabel('time(s)');  ylabel('Joint Acc(rad/s^2)');
grid;

% +++++++++++++++++++++++++++++++++++++++++++++++++
% 笛卡尔空间的轨迹规划曲线
% 有的Matlab版本会影响第一个figure的机器人显示。RTB的bug。
figure('position',[1000, 250, 800,920])
axis equal
for i=1 : Nc
    qc(i,:) = robot.ikine(Tc(:,:,i),'q0', qs0, 'mask', m);
end
robot.plot(qc, 'trail',{'b', 'LineWidth', 2}, 'nowrist', 'notiles');
