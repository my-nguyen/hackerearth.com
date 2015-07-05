# first implementation is correct but took too long: more than 7 minutes for
# the 3rd test case of Input #2 which has 100,000 soldiers.
require 'benchmark'

def process(superiors, soldiers)
  pawn = soldiers[0]
  boss = soldiers[1]
  review_count = 0
  while (superiors[pawn-1] != 0)
    if (superiors[pawn-1] == boss)
      return review_count
    else
      review_count += 1
      pawn = superiors[pawn-1]
    end
  end
  return -1
end

case_count = gets.to_i
case_count.times do
  soldier_count = gets.to_i
  superiors = gets.scan(/\d+/).map(&:to_i)
  query_count = gets.to_i
  time = Benchmark.realtime do
    query_count.times do
      soldiers = gets.scan(/\d+/).map(&:to_i)
        puts process(superiors, soldiers)
    end
  end
  temps = time.to_i
  # puts "Time elapsed: #{temps/60} minutes #{temps%60} seconds"
end
