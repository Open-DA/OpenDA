% Eig-decomposition: generate weight from matrix A
function W = GenerateWeight(A)
disp('=========================');
% matrix decomposition and get max eig
[V, D] = eig(A);
B=max(max(D)); 
[~, col]=find(D==B);
C = V(:, col);
W = C / sum(C);
disp('Weight: ');
disp(W');

% check insistence
[~, n] = size(A);
Check(B, n);

end