# second implementation with multiple arrays, each representing a path from
# soldier to commander.
require 'benchmark'

def build_tree2(army)
  tree = Array.new
  officer = army.index(0)
  cur_branch = Array.new(officer)
  tree << cur_branch

  # find all soldiers reporting to the current officer
  soldiers = army.size.times.select {|i| army[i] == officer+1}
  # for each of the soldiers from the second to last one, create a new branch,
  # each branch composed of a copy of the current branch plus a soldier
  # inserted at the beginning, then add the new branch to the tree
  1.upto(soldiers.length-1) do |i|
    new_branch = Array.new(cur_branch)
    new_branch.insert(0, soldiers[i])
    tree << new_branch
  end
  # insert the first subordinate to the current branch
  cur_branch.insert(0, soldiers[0])

  # recursive call
  soldiers.each do |soldier|
    build_tree(army, soldier)
  end
end

def build_tree
  officer = army.index(0)
  branch = Array.new
  while !(soldiers = army.size.times.select {|i| army[i] == officer+1}).empty?
    branch << soldiers[0]
  end
end

def process(army, soldiers)
  pawn = soldiers[0]
  boss = soldiers[1]
  review_count = 0
  while (army[pawn-1] != 0)
    if (army[pawn-1] == boss)
      return review_count
    else
      review_count += 1
      pawn = army[pawn-1]
    end
  end
  return -1
end

case_count = gets.to_i
case_count.times do
  soldier_count = gets.to_i
  army = gets.scan(/\d+/).map(&:to_i)
  query_count = gets.to_i
  time = Benchmark.realtime do
    query_count.times do
      soldiers = gets.scan(/\d+/).map(&:to_i)
        process(army, soldiers)
    end
  end
  puts "Time elapsed: #{time/60} minutes #{time%60} seconds"
end
