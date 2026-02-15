// ==============================
// Select DOM elements
// ==============================
const solveBtn = document.getElementById("solveBtn");
const equationInput = document.getElementById("equation");
const solutionOutput = document.getElementById("solutionOutput");
const timeOutput = document.getElementById("timeOutput");
const historyList = document.getElementById("historyList");

// ==============================
// Solve button click event
// ==============================
solveBtn.addEventListener("click", async () => {
    const eq = equationInput.value.trim();
    if (!eq) return alert("Please enter an equation!");

    // Show solving animation/message
    solutionOutput.innerHTML = "<em>Solving...</em>";
    timeOutput.innerHTML = "";

    try {
        // Call backend API
        const response = await fetch("http://127.0.0.1:5000/solve", {
            method: "POST",
            headers: { "Content-Type": "application/json" },
            body: JSON.stringify({ equation: eq })
        });

        const data = await response.json();

        // Clear previous solution
        solutionOutput.innerHTML = "";

        if (data.success) {
            // Display solution nicely
            for (const [letter, value] of Object.entries(data.solution)) {
                solutionOutput.innerHTML += `<strong>${letter}</strong> = ${value}<br>`;
            }
            timeOutput.innerHTML = `<strong>Time Taken:</strong> ${data.time_taken.toFixed(4)} sec`;

            // Add to history
            const li = document.createElement("li");
            li.innerHTML = `<strong>${eq}</strong> → Solved in ${data.time_taken.toFixed(4)} sec`;
            historyList.prepend(li);

        } else {
            // Show error nicely
            solutionOutput.innerHTML = `<span style="color:red;"><strong>Error:</strong> ${data.error}</span>`;
            timeOutput.innerHTML = `<strong>Time Taken:</strong> ${data.time_taken.toFixed(4)} sec`;

            // Add to history
            const li = document.createElement("li");
            li.innerHTML = `<strong>${eq}</strong> → Failed`;
            historyList.prepend(li);
        }

    } catch (err) {
        console.error(err);
        alert("Server error! Make sure your backend (api.py) is running.");
        solutionOutput.innerHTML = "";
        timeOutput.innerHTML = "";
    }
});

// ==============================
// Optional: Enter key triggers solve
// ==============================
equationInput.addEventListener("keyup", (event) => {
    if (event.key === "Enter") {
        solveBtn.click();
    }
});
