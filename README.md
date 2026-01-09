#Code Flowchart

```mermaid
graph TD
    %% 定義樣式
    classDef process fill:#e1f5fe,stroke:#01579b,stroke-width:2px;
    classDef decision fill:#fff9c4,stroke:#fbc02d,stroke-width:2px;
    classDef terminator fill:#fce4ec,stroke:#880e4f,stroke-width:2px;
    classDef io fill:#e0f2f1,stroke:#004d40,stroke-width:2px;
    classDef error fill:#ffebee,stroke:#c62828,stroke-width:2px,stroke-dasharray: 5 5;

    Start([程式開始]) --> AskDemo{顯示範例?}
    
    %% 範例區塊
    AskDemo -- Yes --> RunDemo[執行 demo 函式]
    RunDemo --> ShowDemoData[顯示多筆範例資料<br/>包含 Try-Catch 測試]
    ShowDemoData --> LoopStart
    AskDemo -- No --> LoopStart

    %% 主迴圈
    subgraph MainLoop [主程式無窮迴圈]
        LoopStart((迴圈起點))--> InputType[/輸入選項<br/>b:飲料 j:果汁 m:主餐 d:點心 e:結束/]
        InputType --> CheckType{判斷類型}

        %% 結束分支
        CheckType -- e --> End([結束程式])
        
        %% 通用輸入
        CheckType -- b, j, m, d --> CommonInput[[呼叫 foodInfoInput<br/>輸入名稱/熱量/營養素]]
        CommonInput --> SpecificInput{類型分流}

        %% 飲料路徑
        SpecificInput -- b:飲料 --> InputBev[/輸入: 內容物 content/]
        InputBev --> ValidatorB[[呼叫InputValidator<br>過濾、檢查輸入]]
        ValidatorB --> TryBev[建構 Baverage 物件]

        %% 果汁路徑
        SpecificInput -- j:果汁 --> InputJuice[/輸入: 內容物, 果汁含量, 果肉/]
        InputJuice --> ValidatorJ[[呼叫InputValidator<br>過濾、檢查輸入]]
        ValidatorJ --> TryJuice[建構 Juice 物件]

        %% 主餐路徑
        SpecificInput -- m:主餐 --> InputMeal[/輸入: 油炸比例/]
        InputMeal -->ValidatorM[[呼叫InputValidator過濾、檢查輸入]]
        ValidatorM -->TryMeal[建構 Meal 物件]


        %% 點心路徑
        SpecificInput -- d:點心 --> InputDessert[/輸入: 水果, 精緻糖/]
        InputDessert --> ValidatorD[[呼叫InputValidator過濾、檢查輸入]]
        ValidatorD -->TryDessert[建構 Dessert 物件]


        %% 輸出與錯誤處理
        TryBev & TryJuice & TryMeal & TryDessert --> PrintObj[物件.print]
        PrintObj -->LoopStart
        
    end

    %% 套用樣式
    class Start,End,LoopStart terminator;
    class AskDemo,CheckType,SpecificInput,CatchBlock decision;
    class ShowMenu,InputType,InputBev,InputJuice,InputMeal,InputDessert,ShowDemoData io;
    class Setup,RunDemo,CommonInput,TryBev,TryJuice,TryMeal,TryDessert,PrintObj process;