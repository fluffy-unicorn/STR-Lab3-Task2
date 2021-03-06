package RERSlearner;

import com.google.common.collect.ImmutableSet;
import de.learnlib.api.SUL;

import java.io.IOException;
import java.util.Collection;

/**
 * Created by rick on 17/03/2017.
 */
public class RERSExperiment {
    /**
     * Example of how to learn a Mealy machine model from one of the compiled RERS programs.
     * @param args
     * @throws IOException
     */
	// The RERS problem to run
	static final int problem = 11;
	// LStar, RivestSchapire, TTT, KearnsVazirani
	static final BasicLearner.LearningMethod learningMethod = BasicLearner.LearningMethod.TTT;
	// RandomWalk, WMethod, WpMethod, UserQueries
	static final BasicLearner.TestingMethod testingMethod = BasicLearner.TestingMethod.WMethod;
	// Path to RERS problem files
	static final String path = "/home/tinus/master/2018-19/2A/STR/lab3/rers/";
	
	// Get the alphabet based on the problem selected
	private static Collection<String> selectAlphabet(int problem) {
		Collection<String> inputAlphabetA = ImmutableSet.of("1","2","3","4","5","6","7","8","9","10");
		Collection<String> inputAlphabetB = ImmutableSet.of("1","2","3","4","5","6","7","8","9","10","11","12","13","14","15");
		Collection<String> inputAlphabetC = ImmutableSet.of("1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20");

		switch (problem) {
		case 11:
		case 12:
		case 13:
			return inputAlphabetA;
		case 14:
		case 15:
		case 16:
			return inputAlphabetB;
		case 17:
		case 18:
		case 19:
			return inputAlphabetC;
		default:
			return null;
		}
	}

	public static void main(String [] args) throws IOException {
        // Load the System Under Learning (SUL)
        SUL<String,String> sul = new ProcessSUL(path + "Problem" + problem + "/Problem" + problem);

        // the input alphabet
        Collection<String> inputAlphabet = selectAlphabet(problem);

        try {
            // runControlledExperiment for detailed statistics, runSimpleExperiment for just the result
            BasicLearner.runControlledExperiment(System.currentTimeMillis(), "Problem" + problem, sul, learningMethod, testingMethod, inputAlphabet);
        } finally {
            if (sul instanceof AutoCloseable) {
                try {
                    ((AutoCloseable) sul).close();
                } catch (Exception exception) {
                    // should not happen
                }
            }
        }
    }
}