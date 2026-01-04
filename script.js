/* ================= SUBJECT SWITCH ================= */
function showSection(section) {
    document.getElementById("dsa").style.display = "none";
    document.getElementById("oops").style.display = "none";
    document.getElementById(section).style.display = "block";
}

/* ================= LOAD CODE FILE ================= */
function loadCode(file, id) {
    fetch(file)
        .then(res => res.text())
        .then(data => {
            const el = document.getElementById(id);
            if (el) el.textContent = data;
        })
        .catch(() => {
            const el = document.getElementById(id);
            if (el) el.textContent = "Unable to load file.";
        });
}

/* ================= ACCORDION TOGGLE ================= */
function toggleCode(btn) {
    const content = btn.nextElementSibling;
    const isOpen = content.style.display === "block";

    document.querySelectorAll(".content").forEach(c => {
        c.style.display = "none";
    });
    document.querySelectorAll(".title").forEach(t => {
        t.classList.remove("active");
    });

    if (!isOpen) {
        content.style.display = "block";
        btn.classList.add("active");
    }
}

/* ================= SILENT COPY ================= */
function copyCode(codeId, btn) {
    const code = document.getElementById(codeId);
    if (!code) return;

    navigator.clipboard.writeText(code.innerText);

    btn.classList.add("copied");
    setTimeout(() => btn.classList.remove("copied"), 1500);
}

/* ================= LOAD DSA PRACTICAL FILES ================= */
loadCode("codes_dsa/student_linked_list.cpp", "dsa1");
loadCode("codes_dsa/binary_search.cpp", "dsa2");
loadCode("codes_dsa/reverse_linked_list.cpp", "dsa3");
loadCode("codes_dsa/hashing.cpp", "dsa4");
loadCode("codes_dsa/array_students.cpp", "dsa5");
loadCode("codes_dsa/bst.cpp", "dsa6");
loadCode("codes_dsa/2d_array.cpp", "dsa7");
loadCode("codes_dsa/dfs.cpp", "dsa8");
loadCode("codes_dsa/circular_queue.cpp", "dsa9");
loadCode("codes_dsa/undo_redo.cpp", "dsa10");
loadCode("codes_dsa/bubble_sort.cpp", "dsa11");
loadCode("codes_dsa/insertion_sort.cpp", "dsa12");

/* ================= LOAD OOPS PRACTICAL FILES ================= */
loadCode("codes_oops/atm_encapsulation.cpp", "oops1");
loadCode("codes_oops/student_grading.cpp", "oops2");
loadCode("codes_oops/calculator_overloading.cpp", "oops3");
loadCode("codes_oops/complex_operator_overloading.cpp", "oops4");
loadCode("codes_oops/student_database_static_friend.cpp", "oops5");
loadCode("codes_oops/multilevel_inheritance.cpp", "oops6");
loadCode("codes_oops/custom_vector_template.cpp", "oops7");
loadCode("codes_oops/hybrid_inheritance.cpp", "oops8");
