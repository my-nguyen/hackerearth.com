def process(costs, max)
  # first index goes from the beginning until the end of array of costs
  costs.each_index do |first|
    sum = 0
    # last index begins from start until the end of array of costs
    first.upto(costs.length-1) do |last|
      # sum of all costs in between first and last indices
      sum += costs[last]
      # sum equals the max amount Prateek could spend
      if sum == max
        return true
      elsif sum > max
        break
      end
    end
  end

  # if you get to this point, then there was no match
  false
end

# read the number of test cases
gets.to_i.times do
  # read the next 2 numbers: the first is the number of friends, and the second
  # is the maximum amount Prateek can spend on gifts
  numbers = gets.scan(/\d+/).map(&:to_i)
  costs = []
  # read the next number of friends, each representing the gift cost that
  # that friend demands from Prateek
  numbers[0].times do
    costs << gets.to_i
  end

  puts process(costs, numbers[1]) ? "YES" : "NO"
end
