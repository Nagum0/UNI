import org.junit.platform.suite.api.SelectClasses;
import org.junit.platform.suite.api.Suite;

@Suite
@SelectClasses({
    CharacterStatisticsStructureTest.class
    , CharacterStatisticsTest.class
})
public class CharacterStatisticsSuite {}
