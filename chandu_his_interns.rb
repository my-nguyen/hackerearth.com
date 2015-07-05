# only passed 1, 3, 4, 5 and failed the rest (up to 10)
def get_divisors(number)
  divisors = [1]
  2.upto(number/2) do |i|
    #puts("number: #{number}, i: #{i}")
    if (number % i == 0)
      divisors << i
    end
  end
  divisors << number
  #puts(divisors.inspect)
  divisors
end

test_count = gets.to_i
numbers = []
test_count.times do
  puts (get_divisors(gets.to_i).length >= 4 ? "YES": "NO")
end
