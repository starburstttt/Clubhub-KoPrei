sequenceDiagram
    autonumber
    actor Organiser
    participant PWA
    participant ServiceWorker
    participant IndexedDB as IndexedDB Queue
    participant API as Club Hub API

    Note over Organiser, API: Scenario: Wi-Fi drops during Debate Night check-in
    
    Organiser->>PWA: Scan QR code (e.g., student ID e20230117)
    Note over PWA: Wi-Fi Down (Offline)
    PWA->>ServiceWorker: Process check-in locally
    ServiceWorker->>IndexedDB: Store check-in (state: Pending, localId: UUID)
    IndexedDB-->>PWA: Confirm local write
    PWA-->>Organiser: Show instant green tick (marked offline)

    Note over Organiser, API: Network connection restored
    
    API-->>PWA: Network online event / periodic sync triggered
    PWA->>IndexedDB: Fetch pending check-ins
    IndexedDB-->>PWA: Return batch of pending records
    PWA->>API: POST /api/check-ins/batch (batch upload)
    
    alt Server processes batch
        API->>API: Validate each item (check idempotency, registration, duplicate scans)
        API-->>PWA: Return per-item response (Accepted / Rejected with reason)
        PWA->>IndexedDB: Update local states (Accepted / Rejected)
    else Network failure during upload
        API-->>PWA: Timeout / Connection lost
        Note over PWA, IndexedDB: Keep state Pending, retry on next connectivity cycle
    end