emp ={
    name:"walter white",
    age:52,
    city:"Alberqurque",
    job:"chemist supplier"
}

man={
    "id"=>001,
    "status"=>"Alive",
    "job"=>"cop,survivalist"
}

puts emp[:name]
puts man["status"]
--------------------------------------
name = "misbah"
puts "Name: #{name}"

PI=3.1415

def circle_area(radius)
    area=PI*radius**2;
    puts "Area: #{area}"
end

circle_area(5)

num1=10
num2=-5

puts num1-num2

puts Math.sqrt(144)

puts "hello"+","+"world"

s1="hi"
puts s1<<",there";

pr=29.998
puts "price is : #{pr}"

puts "i am learning ruby".upcase
puts "ITS GREAT ?".downcase

is_logged=true
is_admin=false

puts is_admin

val=nil
puts val.nil?

lang=:ruby
puts lang.class

a1=[1,2,3,4]
a2=Array.new(3);
a3=Array.new(3,"hi")
puts a1,a2,a3

mixed=[0.0,"one",2,3,"four"]
puts mixed

matrix =[[0,1,2],
        [1,2,3],
        [2,3,4]]

puts matrix[2][2]

arr=[1,2]
arr.push(3)
# arr<<4
arr.unshift(0)

# arr.pop
# arr.shift
# arr.delete(2)

arr.each do |x|
    puts x
end

# puts "enter age"
# age=gets.to_i
# puts "age is : #{age}"

# if age<18
#     puts "young"
# elsif age<65
#     puts "adult"
# else
#     puts "senior"
# end

age =15
unless age>18
    puts "you are under age"
end

age=22
puts age>=18?"adult":"minor"

grade="a"
case grade
when "a"
    puts "excellent"
when "b"
    puts "great"
when "c"
    puts "good"
when "d"
    puts "average"
else
    puts "poor"
end

for i in 1..5
    puts i
end

[1,2,3].each do |num|
    puts num
end

(1..10).each do |i|
    break if i==5
    puts i
end



# i = 1
# while i != 5
#   puts i
#   i += 1
# end


# a=1
# until a<=25
#     puts a
#     a=a*a
# end
