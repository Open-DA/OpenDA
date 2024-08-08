function B = ismmul(A1, A2)
[A1m, A1n] = size(A1);
[A2m, A2n] = size(A2);
if A1n ~= A2m
    error('error');
end

B = zeros(A1m, A2n);
for i = 1:A1m
    for j = 1:A2n
        temp = 0;
        for k = 1:A1n
            temp = temp + A1(i, k) * A2(k, j);
            if temp > 0
                temp = 1;
            else
                temp = 0;
            end
            B(i, j) = temp;
        end
    end
end
end