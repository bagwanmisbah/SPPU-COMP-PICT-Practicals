import org.apache.hadoop.conf.Configuration;
import org.apache.hadoop.fs.Path;

import org.apache.hadoop.io.Text;
import org.apache.hadoop.io.IntWritable;

import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.Mapper;
import org.apache.hadoop.mapreduce.Reducer;

import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce..lib.output.FileOutputFormat;

import java.util.StringTokenizer;

import javax.naming.ConfigurationException;

import java.io.IOException;

public class WordCountt
{
  public static class TokenizerMapper extends Mapper<Object,Text,Text,IntWritable>
  {
    private static final IntWritable one=new IntWritable(1);
    private static Text word=new Text();

    public void map(Object key,Text values,Context context)throws IOException,InterruptedException
    {
      StringTokenizer itr=new StringTokenizer(values.toString());
      while(itr.hasMoreTokens())
      {
        word.set(itr.nextToken().replaceAll("[^a-zA-Z]","").toLowerCase());
        if(!word.toString().isEmpty())
        {
          context.write(word,one);
        }
      }
    }
  }
  public static class IntSumReducer extends Reducer<Text,IntWritable,Text,IntWritable>
  {
    private IntWritable result=new IntWritable();
    
    public void reduce(Text key,Iterable<IntWritable>values,Context context)throws IOException,InterruptedException
    {
      int sum=0;
      for(IntWritable val:values)
      {
        sum+=val.get();
      }
      result.set(sum);
      context.write(key,result);
    }
  }
  public void main(String[] args)throws InterruptedException
  {
    Configuration conf=new Configuration();
    Job job=Job.getInstance(conf,"word count");
    job.setJarByClass(WordCount.class);
    job.setMapperClass(TokenizerMapper.class);
    job.setReducerClass(IntSumReducer.class);
    job.setCombinerClass(IntSumReducer.class);

    job.setOutputKeyClass(Text.class);
    job.setOutputValueClass(IntWritable.class);
    FileInputFormat.addInputPath(job,new Path(args[0]));
    FileOutputFormat.setOutputFormat(job,new Path(args[1]));
    System.exit(job.waitForCompletion(true)?0:1);

  }
  
}