function [result] = PerformCrossing(speciment, partner, locus)
%UNTITLED2 Zwraca obiekt po skrzy¿owaniu z partnerem przy wybranym lokusie.
result = strcat(speciment(1:locus),partner(locus+1:end));
return
end

