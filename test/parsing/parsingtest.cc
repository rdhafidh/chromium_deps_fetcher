#include <depsfilerepoparser.h>
#include <gtest/gtest.h>
#include <ostream>

TEST(ParseFileTest, TestNull) {
  DepsFileRepoParser p("");

  auto res = p.doParse();
  EXPECT_EQ(false, res.status);
  EXPECT_EQ(false, res.isContainDepsVar);
}

TEST(ParseFileTest, TestInvalidName) {
  DepsFileRepoParser p("SAD l!!");

  auto res = p.doParse();
  EXPECT_EQ(false, res.status);
  EXPECT_EQ(false, res.isContainDepsVar);
}

TEST(ParseFileTest, TestBasic1) {
  std::stringstream fmt;
  fmt << ROOT_TEST_DIR << "/google_deps_grammar.data";
  std::string fname;
  fmt >> fname;
  DepsFileRepoParser p(fname.c_str());
  auto res = p.doParse();
  EXPECT_EQ(true, res.status);
  EXPECT_EQ(3, res.varLineCount);
  EXPECT_EQ(true, res.isContainDepsVar);
}

TEST(ParseFileTest, TestBasic2) {
  std::stringstream fmt;
  fmt << ROOT_TEST_DIR << "/test_var.data";
  std::string fname;
  fmt >> fname;
  DepsFileRepoParser p(fname.c_str());
  auto res = p.doParse();
  EXPECT_EQ(true, res.status);
  EXPECT_EQ(2, res.varLineCount);
  EXPECT_EQ(false, res.isContainDepsVar);
}

TEST(ParseFileTest, TestBasic3) {
  std::stringstream fmt;
  fmt << ROOT_TEST_DIR << "/test1.t";
  std::string fname;
  fmt >> fname;
  DepsFileRepoParser p(fname.c_str());
  auto res = p.doParse();
  EXPECT_EQ(true, res.status);
  EXPECT_EQ(6, res.varLineCount);
}

TEST(ParseFileTest, TestBasic4) {
  std::stringstream fmt;
  fmt << ROOT_TEST_DIR << "/test2.t";
  std::string fname;
  fmt >> fname;
  DepsFileRepoParser p(fname.c_str());
  auto res = p.doParse();
  EXPECT_EQ(true, res.status);
  EXPECT_EQ(4, res.varLineCount);
  EXPECT_EQ(true, res.isContainDepsVar);
}

/*
 * Todo, make this test passing
 * */
TEST(ParseFileTest, LargeChromiumDeps) {
  std::stringstream fmt;
  fmt << ROOT_TEST_DIR << "/chromium_large_deps.data";
  std::string fname;
  fmt >> fname;
  DepsFileRepoParser p(fname.c_str());
  auto res = p.doParse();
  EXPECT_EQ(false, res.status);
  EXPECT_EQ(0, res.varLineCount);
}

int main(int a, char **b) {
  ::testing::InitGoogleTest(&a, b);
  int ret{RUN_ALL_TESTS()};
  return ret;
}