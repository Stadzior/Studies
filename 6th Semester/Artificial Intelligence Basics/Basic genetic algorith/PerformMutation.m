function [result] = PerformMutation(speciment, locus)
%UNTITLED2 Zwraca obiekt po mutacji przy wybranym lokusie.
mutablePartLength = numel(speciment)-locus; %przesuni�cie do mutowalnej cz�ci chromosomu
randomPos = ceil(rand(1)*mutablePartLength)+locus; %losowa pozycja przesuni�ta o lokus
speciment(randomPos) = num2str(~str2double(speciment(randomPos)));
result = speciment;
return
end

