# XR_unconsciousness

flowchart TB
    %% Define Stepwise Process in Subgraphs for Clarity
    subgraph S1["Step 1: Preparation"]
        A1["🩺 Patient Setup"] --> A2["📍 Physical Marking"]
        A2 --> A3["📸 3D Scanning"]
        A3 --> A4["⚠️ Collision Zone Definition"]
    end

    subgraph S2["Step 2: CT Scanning"]
        B1["🛏️ Patient Transfer & Positioning"] --> B2["🎯 Marker Calibration"]
        B2 --> B3["🩻 CT Scan Acquisition"]
        B3 --> B4["📂 DICOM Data Generation"]
    end

    subgraph S3["Step 3: Treatment Planning"]
        C1["📊 DICOM Analysis"] --> C2["🎯 Target Definition"]
        C2 -->|Treatment| C3["📜 RT-Plan Development"]
        C2 -->|Hyperthermia| C4["🔥 Hyperthermia Plan"]
        C3 & C4 --> C5["🔄 Plan Synchronization"]
    end

    subgraph S4["Step 4: Treatment Delivery"]
        D1["🔄 Patient Repositioning"] --> D2["⚙️ System Calibration"]
        D2 --> D3["🔧 Applicator Insertion"]
        D3 --> D4["⚡ Parallel Treatment"]
        D4 --> D5["📡 Real-time Monitoring"]
    end

    subgraph S5["Step 5: Completion"]
        E1["✔️ Treatment Verification"] --> E2["📊 Data Analysis"]
        E2 --> E3["📈 Patient Monitoring"]
    end

    %% Define Stepwise Flow
    S1 -->|Next| S2
    S2 -->|Next| S3
    S3 -->|Next| S4
    S4 -->|Next| S5

    %% Styling for Enhanced Visualization
    classDef default fill:#f9f9f9,stroke:#333,stroke-width:2px;
    classDef step fill:#e6f3ff,stroke:#333,stroke-width:2px,font-size:14px,font-weight:bold;
    
    class S1,S2,S3,S4,S5 step;
