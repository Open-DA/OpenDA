%% Prepare Data
clc; clear;

% C1, C2, C3
L1 = [1 1/2 1/2;
    2 1 1;
    2 1 1];
% C31, C32, C33
L2 = [1 1 1/3;
    1 1 1/3;
    3 3 1];
% C1 (last level)
L31 = [1 1/7 1/7 1/3;
    7 1 1 7/3;
    7 1 1 7/3;
    3 3/7 3/7 1];
L32 = [1 1/5 1/9 1;
    5 1 5/7 5;
    9 7/5 1 9;
    1 1/5 1/9 1];
L33 = [1 3 1 5;
    1/3 1 1/3 5/3;
    1 3 1 5;
    1/5 3/5 1/5 1];
L34 = [1 3 1 3;
    1/3 1 1/3 1;
    1 3 1 3;
    1/3 1 1/3 1];
L35 = [1 3 1/3 5;
    1/3 1 1/9 5/3;
    3 9 1 9;
    1/5 3/5 1/9 1];

%% Check and compute weight
w1 = GenerateWeight(L1);
w2 = GenerateWeight(L2);
w31 = GenerateWeight(L31);
w32 = GenerateWeight(L32);
w33 = GenerateWeight(L33);
w34 = GenerateWeight(L34);
w35 = GenerateWeight(L35);

%% Compute scores
w_top = zeros(5, 1);
w_top(1) = w1(1);
w_top(2) = w1(2);
w_top(3) = w1(3) * w2(1);
w_top(4) = w1(3) * w2(2);
w_top(5) = w1(3) * w2(3);
w_top = w_top / sum(w_top);
w_bot = cat(2, w31, w32, w33, w34, w35);
scores = w_bot * w_top;
disp('得分计算完毕：');
disp('出国      |  读硕      |  直博      |  工作');
disp(scores');