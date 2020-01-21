#include "gmock/gmock.h"
#include <gtest/gtest.h>

#include "soundex.h"

using testing::Eq;

class SoundexEncoding :public testing::Test {
public:
    Soundex soundex;
};

TEST_F(SoundexEncoding, PadsWithZeroToEnsureThreeDigits){
    auto encoded = soundex.Encode("I");
    ASSERT_THAT(encoded, Eq("I000"));
}

TEST_F(SoundexEncoding, RetainsSoleLetterOfOneLetterWord){
    ASSERT_THAT(soundex.Encode("Ab"), Eq("A100"));
}

TEST_F(SoundexEncoding, ReplaceConsonantsWithAppropriateDigits) {
    EXPECT_THAT(soundex.Encode("Ab"), Eq("A100"));
    EXPECT_THAT(soundex.Encode("Ac"), Eq("A200"));
    EXPECT_THAT(soundex.Encode("Ad"), Eq("A300"));
}