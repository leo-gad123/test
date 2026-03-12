const imageInput = document.getElementById("imageInput");
const uploadBtn = document.getElementById("uploadBtn");
const resultDiv = document.getElementById("result");
const addPersonDiv = document.getElementById("addPerson");
const newNameInput = document.getElementById("newName");
const addBtn = document.getElementById("addBtn");

// Upload image to server
uploadBtn.addEventListener("click", async () => {
    if (!imageInput.files.length) return alert("Select an image first!");
    const file = imageInput.files[0];
    const formData = new FormData();
    formData.append("image", file);

    const response = await fetch("http://YOUR_SERVER_IP:5000/recognize", {
        method: "POST",
        body: formData
    });
    const data = await response.json();

    if(data.faces && data.faces.length > 0){
        const face = data.faces[0];
        resultDiv.textContent = `${face.name} - ${face.status}`;

        if(face.status === "Unauthorized"){
            addPersonDiv.style.display = "block";
        } else {
            addPersonDiv.style.display = "none";
        }
    } else {
        resultDiv.textContent = "No face detected";
        addPersonDiv.style.display = "none";
    }
});

// Add new authorized person
addBtn.addEventListener("click", async () => {
    const name = newNameInput.value.trim();
    if(!name) return alert("Enter a name!");

    const file = imageInput.files[0];
    const formData = new FormData();
    formData.append("image", file);
    formData.append("name", name);

    const response = await fetch("http://YOUR_SERVER_IP:5000/add_person", {
        method: "POST",
        body: formData
    });
    const data = await response.json();

    if(data.success){
        alert(`Added ${name} as Authorized`);
        addPersonDiv.style.display = "none";
        resultDiv.textContent = `${name} - Authorized`;
    } else {
        alert("Failed to add person");
    }
});