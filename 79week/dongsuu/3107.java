package algo;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class B3107 {
    public static void main(String[] args) throws IOException {
        List<String> tokens = new ArrayList<>();
        List<String> answerString = new ArrayList<>();

        String ip;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        ip = st.nextToken();
        String[] t = ip.split(":");
        tokens.addAll(Arrays.asList(t));

        for(int i=0; i<tokens.size(); i++){
            StringBuilder answer = new StringBuilder();
            if(tokens.get(i).length() < 4 && tokens.get(i).length() > 0){ // 0의 일부만 생략한 경우
                int needs = 4 - tokens.get(i).length();
                for (int j=0; j<needs; j++) {
                    answer.append("0");
                }
                answer.append(tokens.get(i));
                answerString.add(answer.toString());
            } else if(tokens.get(i).equals("") && i != 0){
                answerString.add(":");
            } else if(tokens.get(i).length() == 4){ // 4자리 모두 차있는 경우
                answer.append(tokens.get(i));
                answerString.add(answer.toString());
            }
        }

        // ::있는 곳 0000 개수맞게 채워줌
        int size = answerString.size();
        for(int i=0; i<answerString.size(); i++){
            if(answerString.get(i).equals(":")){
                int diff = 8 - size + 1;
                answerString.remove(i);
                for(int j=0; j<diff; j++){
                    answerString.add(i, "0000");
                }
            }
        }

        // 뒤에 ::있는 경우
        if(answerString.size() != 8){
            int s = 8 - answerString.size();
            for(int i=0; i<s; i++) answerString.add("0000");
        }

        StringBuilder result = new StringBuilder();
        for(int i=0; i<answerString.size(); i++){
            result.append(answerString.get(i));
            result.append(":");
        }
        result.deleteCharAt(39);


        System.out.println(result);

    }
}
