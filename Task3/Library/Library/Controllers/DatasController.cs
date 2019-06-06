using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using Library.Models;

namespace Library.Controllers
{
    //[Route("api/[controller]")]
    //[ApiController]
    public class DatasController : Controller
    {
        private readonly LibraryContext _context;

        public DatasController(LibraryContext context)
        {
            _context = context;
        }

        // GET: api/Datas
        [HttpGet]
        [Route("api/Datas/Index")]
        public async Task<ActionResult<IEnumerable<Datas>>> GetDatas()
        {
            return await _context.Datas.ToListAsync();
        }

        // GET: api/Datas/5
        [HttpGet]
        [Route("api/Datas/Index/{id}")]
        public async Task<ActionResult<Datas>> GetDatas(int id)
        {
            var datas = await _context.Datas.FindAsync(id);

            if (datas == null)
            {
                return NotFound();
            }

            return datas;
        }

        // PUT: api/Datas/5
        [HttpPut]
        [Route("api/Datas/Edit/{id}")]
        public async Task<IActionResult> PutDatas(int id, Datas datas)
        {
            if (id != datas.Id)
            {
                return BadRequest();
            }

            _context.Entry(datas).State = EntityState.Modified;

            try
            {
                await _context.SaveChangesAsync();
            }
            catch (DbUpdateConcurrencyException)
            {
                if (!DatasExists(id))
                {
                    return NotFound();
                }
                else
                {
                    throw;
                }
            }

            return NoContent();
        }

        // POST: api/Datas
        [HttpPost]
        [Route("api/Datas/Create")]
        public async Task<ActionResult<Datas>> PostDatas(Datas datas)
        {
            _context.Datas.Add(datas);
            await _context.SaveChangesAsync();

            return CreatedAtAction("GetDatas", new { id = datas.Id }, datas);
        }

        // DELETE: api/Datas/5
        [HttpDelete]
        [Route("api/Datas/Delete/{id}")]
        public async Task<ActionResult<Datas>> DeleteDatas(int id)
        {
            var datas = await _context.Datas.FindAsync(id);
            if (datas == null)
            {
                return NotFound();
            }

            _context.Datas.Remove(datas);
            await _context.SaveChangesAsync();

            return datas;
        }

        private bool DatasExists(int id)
        {
            return _context.Datas.Any(e => e.Id == id);
        }
    }
}
