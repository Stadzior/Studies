function [result] = PerformMutation(speciment, locus)
%UNTITLED2 Zwraca obiekt po mutacji przy wybranym lokusie.
mutablePartLength = numel(speciment)-locus; %przesunięcie do mutowalnej części chromosomu
randomPos = ceil(rand(1)*mutablePartLength)+locus; %losowa pozycja przesunięta o lokus
speciment(randomPos) = num2str(~str2double(speciment(randomPos)));
result = speciment;
return
end

