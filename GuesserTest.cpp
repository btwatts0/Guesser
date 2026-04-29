/**
 * Unit Tests for the class
**/

#include <gtest/gtest.h>
#include "Guesser.h"

class GuesserTest : public ::testing::Test
{
	protected:
		GuesserTest(){} //constructor runs before each test
		virtual ~GuesserTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};


TEST(GuesserTest, same_distance)
{
  Guesser secret("Secret");
  ASSERT_EQ(0, secret.distance("Secret"));
}

TEST(GuesserTest, one_wrong_distance)
{
  Guesser secret("Secret");
  ASSERT_EQ(1, secret.distance("Secres"));
}

TEST(GuesserTest, first_one_wrong_distance)
{
  Guesser secret("Secret");
  ASSERT_EQ(1, secret.distance("Tecret"));
}

TEST(GuesserTest, all_wrong_distance)
{
  Guesser secret("Secret");
  ASSERT_EQ(6, secret.distance("Tfdsfy"));
}

TEST(GuesserTest, displaced_by_one_distance)
{
  Guesser secret("Secret");
  ASSERT_EQ(6, secret.distance("tSecre"));
}

TEST(GuesserTest, empty_guess_distance)
{
  Guesser secret("Secret");
  ASSERT_EQ(6, secret.distance(""));
}

TEST(GuesserTest, longer_guess_distance)
{
  Guesser secret("Secret");
  ASSERT_EQ(1, secret.distance("Secrets"));
}

TEST(GuesserTest, shorter_guess_distance)
{
  Guesser secret("Secret");
  ASSERT_EQ(1, secret.distance("Secre"));
}

TEST(GuesserTest, massively_longer_guess_distance)
{
  Guesser secret("Secret");
  ASSERT_EQ(6, secret.distance("aaaaaaaaaaaaaaaaaaaaaaaaaa"));
}

TEST(GuesserTest, match_then_massively_longer_guess_distance)
{
  Guesser secret("Secret");
  ASSERT_EQ(6, secret.distance("Secretaaaaaaaaaaaaaaaaaaaaaaaa"));
}

TEST(GuesserTest, empty_object_empty_guess_distance)
{
  Guesser secret("");
  ASSERT_EQ(0, secret.distance(""));
}

TEST(GuesserTest, empty_object_nonempty_guess_distance)
{
  Guesser secret("");
  ASSERT_EQ(0, secret.distance("Secret"));
}

TEST(GuesserTest, more_than_32_different_distance_)
{
  Guesser secret("abcdefghijklmnopqrstuvwxyz1234567");
  ASSERT_EQ(0, secret.distance("abcdefghijklmnopqrstuvwxyz123456"));
}

TEST(GuesserTest, more_than_32_same_distance)
{
  Guesser secret("abcdefghijklmnopqrstuvwxyz1234567");
  ASSERT_EQ(1, secret.distance("abcdefghijklmnopqrstuvwxyz1234567"));
}

TEST(GuesserTest, correct_match){
  Guesser secret("Secret");
  ASSERT_TRUE(secret.match("Secret"));
}

TEST(GuesserTest, incorrect_match){
  Guesser secret("Secret");
  ASSERT_FALSE(secret.match("Secres"));
}

TEST(GuesserTest, correct_2nd_time){
  Guesser secret("Secret");
  secret.match("Secres");
  ASSERT_TRUE(secret.match("Secret"));
}

TEST(GuesserTest, correct_3rd_time){
  Guesser secret("Secret");
  secret.match("Secres");
  secret.match("Secres");
  ASSERT_TRUE(secret.match("Secret"));
}

TEST(GuesserTest, correct_4th_time){
  Guesser secret("Secret");
  secret.match("Secres");
  secret.match("Secres");
  secret.match("Secres");
  ASSERT_FALSE(secret.match("Secret"));
}

TEST(GuesserTest, correct_3rd_time_then_correct_5th_time){
  Guesser secret("Secret");
  secret.match("Secres");
  secret.match("Secres");
  secret.match("Secret");
  secret.match("Secres");
  ASSERT_TRUE(secret.match("Secret"));
}

TEST(GuesserTest, locked_out_then_correct){
  Guesser secret("Secret");
  secret.match("a");
  ASSERT_FALSE(secret.match("Secret"));
}