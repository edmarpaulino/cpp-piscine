/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 18:49:46 by edpaulin          #+#    #+#             */
/*   Updated: 2023/09/05 19:57:05 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include "easyfind.hpp"

static void printBugSeparator(void);
static void testWithVector(void);
static void testWithDeque(void);
static void testWithList(void);

int main(void) {
  printBugSeparator();
  testWithVector();
  printBugSeparator();
  testWithDeque();
  printBugSeparator();
  testWithList();
  printBugSeparator();
  return 0;
}

static void printBugSeparator(void) {
  std::cout
    << std::endl
    << "🐛🐛🐛🐛🐛🐛🐛🐛🐛🐛🐛🐛🐛🐛🐛🐛🐛🐛🐛🐛🐛🐛🐛🐛🐛🐛🐛🐛🐛🐛🐛🐛🐛🐛🐛🐛🐛🐛🐛🐛"
    << std::endl
    << std::endl;
}

static void testWithVector(void) {
  std::cout << "🧪 TEST WITH VECTOR 🧪" << std::endl << std::endl;
  {
    const std::string description = "Should throw an exception if the first param is an empty container";
    std::string testResult = "❌ FAIL ❌";
    std::vector<int> vec;
    try {
      easyfind(vec, 42);
    } catch (const std::exception &e) {
      testResult = "✅ PASS ✅";
    }
    std::cout << testResult << " - " << description << std::endl;
  }
  {
    const std::string description = "Should throw an exception if the second param is not found";
    std::string testResult = "❌ FAIL ❌";
    std::vector<int> vec;
    for (int i = -10000; i < 10000; i++) {
      if (i == 42) continue;
      vec.push_back(i);
    }
    try {
      easyfind(vec, 42);
    } catch (const std::exception &e) {
      testResult = "✅ PASS ✅";
    }
    std::cout << testResult << " - " << description << std::endl;
  }
  {
    const std::string description = "Should return an iterator if the second param is found";
    std::string testResult = "❌ FAIL ❌";
    std::vector<int> vec;
    for (int i = -10000; i < 10000; i++) {
      vec.push_back(i);
    }
    try {
      std::vector<int>::iterator result = easyfind(vec, 42);
      if (result != vec.end() && *result == 42) {
        testResult = "✅ PASS ✅";
      }
    } catch (const std::exception &e) {}
    std::cout << testResult << " - " << description << std::endl;
  }
}

static void testWithDeque(void) {
  std::cout << "🧪 TEST WITH DEQUE 🧪" << std::endl << std::endl;
  {
    const std::string description = "Should throw an exception if the first param is an empty container";
    std::string testResult = "❌ FAIL ❌";
    std::deque<int> deq;
    try {
      easyfind(deq, 42);
    } catch (const std::exception &e) {
      testResult = "✅ PASS ✅";
    }
    std::cout << testResult << " - " << description << std::endl;
  }
  {
    const std::string description = "Should throw an exception if the second param is not found";
    std::string testResult = "❌ FAIL ❌";
    std::deque<int> deq;
    for (int i = -10000; i < 10000; i++) {
      if (i == 42) continue;
      deq.push_back(i);
    }
    try {
      easyfind(deq, 42);
    } catch (const std::exception &e) {
      testResult = "✅ PASS ✅";
    }
    std::cout << testResult << " - " << description << std::endl;
  }
  {
    const std::string description = "Should return an iterator if the second param is found";
    std::string testResult = "❌ FAIL ❌";
    std::deque<int> deq;
    for (int i = -10000; i < 10000; i++) {
      deq.push_back(i);
    }
    try {
      std::deque<int>::iterator result = easyfind(deq,42);
      if (result != deq.end() && *result == 42) {
        testResult = "✅ PASS ✅";
      }
    } catch (const std::exception &e) {}
    std::cout << testResult << " - " << description << std::endl;
  }
}

static void testWithList(void) {
  std::cout << "🧪 TEST WITH LIST 🧪" << std::endl << std::endl;
  {
    const std::string description = "Should throw an exception if the first param is an empty container";
    std::string testResult = "❌ FAIL ❌";
    std::list<int> lis;
    try {
      easyfind(lis, 42);
    } catch (const std::exception &e) {
      testResult = "✅ PASS ✅";
    }
    std::cout << testResult << " - " << description << std::endl;
  }
  {
    const std::string description = "Should throw an exception if the second param is not found";
    std::string testResult = "❌ FAIL ❌";
    std::list<int> lis;
    for (int i = -10000; i < 10000; i++) {
      if (i == 42) continue;
      lis.push_back(i);
    }
    try {
      easyfind(lis, 42);
    } catch (const std::exception &e) {
      testResult = "✅ PASS ✅";
    }
    std::cout << testResult << " - " << description << std::endl;
  }
  {
    const std::string description = "Should return an iterator if the second param is found";
    std::string testResult = "❌ FAIL ❌";
    std::list<int> lis;
    for (int i = -10000; i < 10000; i++) {
      lis.push_back(i);
    }
    try {
      std::list<int>::iterator result = easyfind(lis, 42);
      if (result != lis.end() && *result == 42) {
        testResult = "✅ PASS ✅";
      }
    } catch (const std::exception &e) {}
    std::cout << testResult << " - " << description << std::endl;
  }
}
