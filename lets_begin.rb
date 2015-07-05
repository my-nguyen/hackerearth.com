def process number
  # special case when number is 1
  if (number == 1)
    return -1
  else
    # with the single-digit prime numbers as: 2, 3, 5, 7
    # take the division by the largest single-digit prime number (7)
    division = number / 7
    # examine the remainder of the division,
    case number % 7
    when 0
      surplus = 0
    when 1
      # 8 = 5 + 3
      surplus = 1
    when 2
      # 9 = 7 + 2
      surplus = 1
    when 3
      # 10 = 7 + 3
      surplus = 1
    when 4
      # 11 = 7 + 2 + 2
      surplus = 2
    when 5
      # 12 = 7 + 5
      surplus = 1
    when 6
      # 13 = 7 + 3 + 3
      surplus = 2
    end

    return division + surplus
  end
end

# read the number of test cases
gets.to_i.times do
  puts process(gets.to_i)
end
