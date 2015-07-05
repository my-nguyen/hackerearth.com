require 'benchmark'
# failed all tests

# read input
numbers = gets.split.map {|i| i.to_i}
first = numbers[0]
modulo = numbers[1]
days = gets.chomp
# puts("first: #{first}, modulo: #{modulo}, days: #{days}")

# pre-calculate all values in an array of potions based on the number of days
potions = [first]
time1 = Benchmark.realtime do
  (days.length-1).times do |index|
    # puts("index: #{index}, inserting: #{potions[index]*potions[index]}")
    potions << potions[index]*potions[index]
  end
  # puts(potions.inspect)
end
puts "Time elapsed: #{time1%60} seconds"

# take the total potions on the day you're allowed to shop
sum = 0
time2 = Benchmark.realtime do
  days.length.times do |index|
    # puts("days[index]: #{days[index]}")
    if days[index] == '1'
      sum += potions[index]
    end
  end
end
puts "Time elapsed: #{time2%60} seconds"

# result is modulo
# puts("sum: #{sum}")
puts(sum % modulo)
