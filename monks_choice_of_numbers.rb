# Monk loves cakes! He visits the Binary Bakery to buy some of his favorite
# cheesecakes.
# The owner of the bakery, Bob, is a clever man. He does not want Monk to finish
# all his cheesecakes. Hence, he plays a game.
# The Monk is given N numbers and has to select K of these numbers. For each
# number that Monk chooses, he will get as many cheesecakes as the number of 1's
# in the Binary representation of the number i.e. the number of bits that are set.
# Help Monk find the maximum number of cakes that he can have.
#
# Input:
# The first line of input contains T. T test cases follow.
# First line of each test cases contains 2 space-separated integers N and K.
# The next line contains N space-separated integers.
#
# Output:
# For each test cases, print the answer in a new line.
#
# Constraints:
# 1 ≤ T ≤ 10
# 1 ≤ N ≤ 103
# 0 ≤ K ≤ N
# 0 ≤ Numbers ≤ 105
#
# Sample Input
# 1
# 4 2
# 6 1 2 0
#
# Sample Output
# 3
#
# Explanation
# He chooses numbers 6 (110) and 1 (001) with 2 and 1 set bits respectively.
################################################################################
# tough algorithm!!!
# Given an array of integers such as [6, 1, 2, 0], select n integers which when
# combined have the maximum number of 1 bits
# My thoughts:
# N is numbers.size; must select K from N
# Must select K numbers.
# In each loop, iterate from "start" for "difference between current size and K,
# plus 1" times
# For example
# To select the 1st number, iterate (i1) from 0 for N-K+1 times
# To select the 2nd number, iterate (i2) from (i1+1) for (N-i1-K+1) times
# To select the 3rd number, iterate (i3) from (i2+1) for (N-i2-K+1) times
# etc.
# So taking the sample input as an example, with N=4, K=2, numbers=[6, 1, 2, 0]
# We need to select K (2) integers
# To select the 1st integer, iterate (i1) from 0 for N-K+1(3) times
# To select the 2nd integer, iterate (i2) from i1+1 for N-i1-K+1 times
def select_k(numbers, n, k, iprevious, max)


  # count the number of 1 bits in an integer by first converting the integer to
  # a binary string, before calling String::count
  # Like so: number.to_s(2).count('1')
end

def something
end

# helper method to print content of an array of integers
def print_array(numbers)
  numbers.each do |number|
    print "#{number} "
  end
  puts
end

case_count = gets.to_i
case_count.times do |ca|
  n_k = gets.split.map(&:to_i)
  puts("n: #{n_k[0]}, k: #{n_k[1]}")
  knumbers = gets.split.map(&:to_i)
  print_array(knumbers)
end
