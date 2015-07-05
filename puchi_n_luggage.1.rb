# Total 7 test inputs. Failed inputs #6 and #7 (took too long)
def myprint(lighters)
  lighters.each do |lighter|
    print("#{lighter} ")
  end
  puts
end

def process(weights)
  lighters = []
  weights.each_index do |index|
    lighter = 0
    (index+1).upto(weights.length-1) do |jndex|
      lighter += 1 if weights[jndex] < weights[index]
    end
    lighters << lighter
  end
  lighters
end

case_count = gets.to_i
case_count.times do
  weight_count = gets.to_i
  weights = []
  weight_count.times do
    weights << gets.to_i
  end
  myprint(process(weights))
end
