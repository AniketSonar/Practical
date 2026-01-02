/* Load external code files */
function loadCode(file, id) {
    fetch(file)
        .then(res => res.text())
        .then(data => {
            document.getElementById(id).textContent = data;
        })
        .catch(() => {
            document.getElementById(id).textContent = "Unable to load file.";
        });
}

/* Toggle accordion (open/close same title) */
function toggleCode(btn) {
    const content = btn.nextElementSibling;
    const isOpen = content.style.display === "block";

    document.querySelectorAll(".content").forEach(c => c.style.display = "none");
    document.querySelectorAll(".title").forEach(t => t.classList.remove("active"));

    if (!isOpen) {
        content.style.display = "block";
        btn.classList.add("active");
    }
}

/* Silent copy */
function copyCode(codeId, btn) {
    navigator.clipboard.writeText(
        document.getElementById(codeId).innerText
    );

    btn.classList.add("copied");
    setTimeout(() => btn.classList.remove("copied"), 1500);
}

// ===== Load all practical code files =====
loadCode("codes/student_linked_list.cpp", "code1");
loadCode("codes/binary_search.cpp", "code2");
loadCode("codes/reverse_linked_list.cpp", "code3");
loadCode("codes/hashing.cpp", "code4");
loadCode("codes/array_students.cpp", "code5");
loadCode("codes/bst.cpp", "code6");
loadCode("codes/2d_array.cpp", "code7");
loadCode("codes/dfs.cpp", "code8");
loadCode("codes/circular_queue.cpp", "code9");
loadCode("codes/undo_redo.cpp", "code10");
loadCode("codes/bubble_sort.cpp", "code11");
loadCode("codes/insertion_sort.cpp", "code12");
