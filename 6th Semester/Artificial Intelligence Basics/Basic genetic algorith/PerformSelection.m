function [parentGeneration] = PerformSelection(PopulationDec)
%Ko³o ruletki

    %Ocena przystosowania
    adaptationRating = AdaptationFunction(PopulationDec);
    populationCount = size(PopulationDec,1);
    survivingChances = adaptationRating/sum(adaptationRating);
    parentGeneration = zeros(populationCount,1);
    for i = 1:populationCount         
        fateValue = rand();
        comparisonValue = 0;
        for j = 1:populationCount
            comparisonValue = comparisonValue + survivingChances(j);
            survived = fateValue<=comparisonValue;
            if(survived)
                disp(['Wybrano: ', num2str(PopulationDec(j))]);
                parentGeneration(i) = PopulationDec(j);
                break;
            end;
        end;
    end;
return
end

