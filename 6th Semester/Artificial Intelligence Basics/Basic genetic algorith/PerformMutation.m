function [result] = PerformMutation(speciment, locus)
%UNTITLED2 Zwraca obiekt po mutacji przy wybranym lokusie.
mutablePartLength = numel(speciment)-locus; %przesuniêcie do mutowalnej czêœci chromosomu
randomPos = ceil(rand(1)*mutablePartLength)+locus; %losowa pozycja przesuniêta o lokus
speciment(randomPos) = num2str(~str2double(speciment(randomPos)));
result = speciment;
return
end

