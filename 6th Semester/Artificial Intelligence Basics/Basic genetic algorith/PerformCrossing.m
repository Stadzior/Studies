function [result] = PerformCrossing(speciment, partner, locus)
%UNTITLED2 Zwraca obiekt po skrzyżowaniu z partnerem przy wybranym lokusie.
result = strcat(speciment(1:locus),partner(locus+1:end));
return
end

